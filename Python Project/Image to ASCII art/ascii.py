from PIL import Image,ImageDraw,ImageFont
import argparse


def get_char(r,g,b,alpha = 256): #获取灰度值对应字符
    ls="$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1[]?-_+~<>i!lI;:,\"^`'. "
    if alpha == 0:
        return ' '
    length = len(ls)
    # 将 RGB 值转为灰度值 gray，灰度值范围为 0-255
    gray = int(0.299 * r + 0.587 * g + 0.114 * b)

    return ls[int(gray/256*length)]

def get_argument(): #获取参数
    parser = argparse.ArgumentParser()
    parser.add_argument('file',type=str)
    parser.add_argument('--width',type=int)
    parser.add_argument('--height',type=int)
    parser.add_argument('-o',type=str)
    args = parser.parse_args()
    file = args.file
    width = args.width
    height = args.height
    output = args.o
    if output is None:
        output = 'output.png'
    if width is None:
        width = 500
    if height is None:
        height = 500
    return file,width,height,output

def process_image(file,width=500,height=500): #处理图片
    im = Image.open(file)
    im = im.resize((width,height), Image.NEAREST)
    #text用来存储转换后的内容
    text = ''
    for y in range(height):
        for x in range(width):
            text += get_char(*im.getpixel((x,y)))
        text += '\n'
    return text

def text_to_image(image_width,image_height,text, font_size=30, file_name='output_image.png'):
    # 创建一个白色背景的图像
    background_color = (255, 255, 255)  # 白色背景
    image = Image.new('RGB', (image_width, image_height), background_color)
    
    # 创建一个 Draw 对象
    draw = ImageDraw.Draw(image)

    # 使用默认字体，也可以加载自定义字体
    try:
        font = ImageFont.truetype("arial.ttf", font_size)
    except IOError:
        font = ImageFont.load_default()  # 如果没有找到指定的字体，使用默认字体

    print("正在计算边界框")
    # 计算文本的边界框
    bbox = draw.textbbox((0, 0), text, font)

    print("获取边界框的宽度与高度")
    # 获取边界框的宽度和高度
    text_width = bbox[2] - bbox[0]  # bbox[2] 是右下角的 x 坐标，bbox[0] 是左上角的 x 坐标
    text_height = bbox[3] - bbox[1]  # bbox[3] 是右下角的 y 坐标，bbox[1] 是左上角的 y 坐标

    print("计算文本位置")
    # 计算文本的位置，使其居中
    text_x = (image_width - text_width) // 2
    text_y = (image_height - text_height) // 2

    print("绘制文本")
    # 绘制文本
    text_color = (0, 0, 0)  # 黑色文本
    draw.text((text_x, text_y), text, font=font, fill=text_color)

    print("保存图片")
    # 保存图像
    image.save(file_name)
    print(f'图像已保存为 {file_name}')

if __name__ == '__main__':
    file,width,height,output = get_argument()
    print('正在处理图片')
    im = process_image(file,width,height)
    print("正在输出")
    text_to_image(width,height,im,30,output)
