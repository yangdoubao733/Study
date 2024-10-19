import argparse

# 1. 创建 ArgumentParser 对象
parser = argparse.ArgumentParser(description='Example of argparse usage.')

# 2. 添加参数
# 添加一个位置参数
parser.add_argument('name', type=str, help='Your name')

# 添加一个可选参数
parser.add_argument('--age', type=int, help='Your age')

# 3. 解析参数
args = parser.parse_args()

# 4. 使用参数
print(f'Hello, {args.name}!')
if args.age is not None:
    print(f'You are {args.age} years old.')