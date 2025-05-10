// 获取DOM元素
const taskInput = document.getElementById('taskInput');
const addBtn = document.getElementById('addBtn');
const taskList = document.getElementById('taskList');
const taskCount = document.getElementById('taskCount');
const clearCompletedBtn = document.getElementById('clearCompletedBtn');
const filterBtns = document.querySelectorAll('.filter-btn');

// 当前过滤状态
let currentFilter = 'all';

// 任务数组
let tasks = JSON.parse(localStorage.getItem('tasks')) || [];

// 初始化应用
function init() {
    renderTasks();
    updateTaskCount();
    
    // 添加事件监听器
    addBtn.addEventListener('click', addTask);
    taskInput.addEventListener('keypress', (e) => {
        if (e.key === 'Enter') addTask();
    });
    clearCompletedBtn.addEventListener('click', clearCompleted);
    
    // 过滤按钮事件
    filterBtns.forEach(btn => {
        btn.addEventListener('click', () => {
            filterBtns.forEach(b => b.classList.remove('active'));
            btn.classList.add('active');
            currentFilter = btn.getAttribute('data-filter');
            renderTasks();
        });
    });
}

// 添加新任务
function addTask() {
    const taskText = taskInput.value.trim();
    if (taskText === '') return;
    
    const newTask = {
        id: Date.now(),
        text: taskText,
        completed: false,
        createdAt: new Date()
    };
    
    tasks.push(newTask);
    saveTasks();
    renderTasks();
    updateTaskCount();
    
    // 清空输入框并聚焦
    taskInput.value = '';
    taskInput.focus();
}

// 切换任务完成状态
function toggleTask(id) {
    tasks = tasks.map(task => {
        if (task.id === id) {
            return { ...task, completed: !task.completed };
        }
        return task;
    });
    
    saveTasks();
    renderTasks();
    updateTaskCount();
}

// 删除任务
function deleteTask(id) {
    tasks = tasks.filter(task => task.id !== id);
    saveTasks();
    renderTasks();
    updateTaskCount();
}

// 清除已完成任务
function clearCompleted() {
    tasks = tasks.filter(task => !task.completed);
    saveTasks();
    renderTasks();
    updateTaskCount();
}

// 渲染任务列表
function renderTasks() {
    // 清空任务列表
    taskList.innerHTML = '';
    
    // 根据过滤条件筛选任务
    let filteredTasks = tasks;
    if (currentFilter === 'active') {
        filteredTasks = tasks.filter(task => !task.completed);
    } else if (currentFilter === 'completed') {
        filteredTasks = tasks.filter(task => task.completed);
    }
    
    // 如果没有任务，显示提示信息
    if (filteredTasks.length === 0) {
        const emptyMessage = document.createElement('li');
        emptyMessage.className = 'todo-item empty';
        emptyMessage.textContent = currentFilter === 'all' ? '没有任务，添加一个吧！' : 
                                  currentFilter === 'active' ? '没有未完成的任务！' : '没有已完成的任务！';
        taskList.appendChild(emptyMessage);
        return;
    }
    
    // 渲染任务
    filteredTasks.forEach(task => {
        const li = document.createElement('li');
        li.className = `todo-item ${task.completed ? 'completed' : ''}`;
        
        const checkbox = document.createElement('input');
        checkbox.type = 'checkbox';
        checkbox.checked = task.completed;
        checkbox.addEventListener('change', () => toggleTask(task.id));
        
        const label = document.createElement('label');
        label.textContent = task.text;
        
        const deleteBtn = document.createElement('button');
        deleteBtn.className = 'delete-btn';
        deleteBtn.innerHTML = '&times;';
        deleteBtn.addEventListener('click', () => deleteTask(task.id));
        
        li.appendChild(checkbox);
        li.appendChild(label);
        li.appendChild(deleteBtn);
        
        taskList.appendChild(li);
    });
}

// 更新任务计数
function updateTaskCount() {
    const activeCount = tasks.filter(task => !task.completed).length;
    taskCount.textContent = `${activeCount} 个待办事项`;
}

// 保存任务到本地存储
function saveTasks() {
    localStorage.setItem('tasks', JSON.stringify(tasks));
}

// 初始化应用
document.addEventListener('DOMContentLoaded', init);