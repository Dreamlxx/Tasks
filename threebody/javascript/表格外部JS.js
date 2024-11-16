//新增数据函数
function addRow() {
    var table = document.getElementById('table');
    var length = table.rows.length;
    // 获取插入位置
    // console.log(length);
    //插入行节点
    var newRow = table.insertRow(length);
    console.log(newRow);
    //插入列节点对象
    var namecol = newRow.insertCell(0);
    var phonecol = newRow.insertCell(1);
    var actioncol = newRow.insertCell(2);

    //修改文本节点内容
    namecol.innerHTML = '未命名';
    actioncol.innerHTML = '<button onclick="editRow(this)">编辑</button><button onclick="deletRow(this)">删除</button>';
    phonecol.innerHTML = '无联系方式';
}    


//删除数据函数
function deletRow(button) {
    var row = button.parentNode.parentNode;
    console.log(row);
    row.parentNode.removeChild(row);
}



//编辑数据函数
function editRow(button) {
    var row = button.parentNode.parentNode;
    var name = row.cells[0];
    var phone = row.cells[1];

    //调用弹窗，修改数据
    var inputname = prompt("请输入名字：");
    var inputphone = prompt("请输入手机号：");
    
    
    name.innerHTML = inputname;
    phone.innerHTML = inputphone;
}

