# HTML的学习与使用：

## 一、什么是HTML

- HTML的作用是为网页提供结构，告诉浏览器哪些是标题、段落、列表
- 用标签来实现

### 标签(双标签)

####  段落标签

1. 开始标签<p>
2. 结束标签</p>

#### 一级标题标签

1. </h1>
2. </h1>

#### 超链接标签（网页、邮箱）

1. <a>
2. </a>

### 单标签

1. <input>

2. <br>换行

3. <hr分割线标签
### ==单标签用于没有内容的元素，双标签用于有内容的元素==

## HTML文件结构

### 基本结构：

* <!DOCTYPE html>告诉浏览器，这是HTML文件
	<html>//根元素，相当于起始点，最外层容器

    <head>
        //中间是原始信息，如css,js
    </head>


​    <body>
​        //文本、图像、链接
​    </body>

### ==直接！+TAB+回车（直接打出来完整基本结构）==

## 三、写在<body>里的标签

### 1.标题标签

<h1-6>（双标签）一共六种，用法类似于#；

### 2.段落标签

p     (双标签)

### 3.更改文本标签（都是双标签）

b 加粗；

i 斜体；

u 下划线；

s 删除线；

ul无序标签（如同md里的- ）（中间元素在<li></li>之间写）；

ol有序列表（中间元素在<li></li>之间写）；

<table border=4>（border是属性，表格边框大小）
    <tr>
        <th>//列标题</th>
    </tr>   
    <tr>行（列在行中）
        <td></td>//列
    </tr>
</table>



## 四、标签属性

### 1.基本语法：

<开始标签 属性名=“属性值”>

### 2.每个HTML可以有很多属性

- <p有id和class
- <a有herb
- <img有src和alt(img是图片标签)

### 3.属性名不区分大小写，属性值对大小写敏感

### 4.大多数都有的标签（等css）

- class为HTML定义一个或多个类名(name)
- id定义元素唯一的id()
- style规定元素的行内样式

## 五、块元素与行内元素

### 块

1. 占据整行

### 行

1. 占据所需

### 新增块级标签

1. <div</div将每个分块隔开，相当于一个一个的板子，在里面写具体内容
2. <span></span>给部分文本添加东西，也可以当printf使用

## 六、表单

## 1.<form>

表单的内容全在form里，属性有action

### 2.<input>

- type:规定了input的元素类型。



## 找到的常用标签：

在 HTML 中，常用标签分为不同类型，根据功能和用途来分类。以下是一些常见的 HTML 标签及其用途：

1. 文档结构标签
<html>：定义整个 HTML 文档。
<head>：包含页面的元数据（如标题、样式表、脚本等）。
<body>：定义页面的主体内容。
<title>：定义网页的标题，显示在浏览器的标签栏中。
<meta>：定义文档的元数据，如字符集、作者、描述等。
2. 文本格式化标签
<h1> 到 <h6>：定义标题，<h1> 为最大标题，<h6> 为最小标题。
<p>：定义段落。
<b>：使文本加粗（已过时，推荐使用 <strong>）。
<i>：使文本倾斜（已过时，推荐使用 <em>）。
<strong>：定义重要文本，通常加粗。
<em>：定义强调文本，通常以斜体显示。
<br>：换行标签。
<hr>：创建水平分隔线。
3. 链接与导航标签
<a>：定义超链接。
href 属性用于指定链接目标。
示例：<a href="https://www.example.com">点击这里</a>
<nav>：定义导航链接。
4. 列表标签
<ul>：无序列表（默认使用圆点标记）。
<ol>：有序列表（默认使用数字标记）。
<li>：定义列表项。
5. 表格标签
<table>：定义表格。
<tr>：定义表格行。
<th>：定义表格头单元格，通常为加粗居中的文本。
<td>：定义表格数据单元格。
<caption>：为表格定义标题。
<thead>：定义表格头部。
<tbody>：定义表格主体。
<tfoot>：定义表格尾部。
6. 表单标签
<form>：定义表单，用于收集用户输入。
<input>：定义输入字段，可以是文本框、单选框、复选框等。
常见 type 属性：text, password, radio, checkbox, submit, button 等。
<textarea>：定义多行文本框。
<select>：定义下拉列表。
<option>：定义下拉列表中的选项。
<label>：为表单控件定义标签。
<button>：定义按钮。
7. 多媒体标签
<img>：定义图像。
src 属性指定图像文件的路径。
alt 属性提供图像的替代文本。
<audio>：定义音频内容。
controls 属性显示音频控件（播放、暂停、音量等）。
<video>：定义视频内容。
controls 属性显示视频控件（播放、暂停、音量等）。
<source>：为 <audio> 和 <video> 标签定义多媒体文件的不同格式。
8. 语义化标签
<header>：定义页面的头部区域，通常包含网站导航和标题。
<footer>：定义页面的底部区域，通常包含版权信息、联系信息等。
<article>：定义独立的内容单元（如博客文章、新闻报道等）。
<section>：定义页面的一个区域或章节。
<aside>：定义与页面内容间接相关的区域，通常用于侧边栏。
<main>：定义页面的主体内容区域。
9. 容器与布局标签
<div>：定义一个块级容器，用于布局和结构。
<span>：定义一个内联容器，通常用于样式化部分文本。
<header>、<footer>、<section>、<article>：用于网页的结构化布局，提供更好的语义标记。
10. 内嵌样式与脚本标签
<style>：定义内部 CSS 样式。
<script>：定义内部 JavaScript 脚本。
<link>：在页面头部链接外部 CSS 文件。
<iframe>：定义一个嵌入的网页，通常用于嵌入其他页面或媒体。
11. 其他常用标签
<meta>：定义页面的元信息，如字符集、视口设置、页面描述等。
<link>：定义与文档相关的外部资源，通常用于链接样式表。
<base>：指定页面中的所有相对链接的基础 URL。
<mark>：用于突出显示文本，通常是背景色高亮。
<code>：定义一段代码文本。
<pre>：定义预格式化文本，通常保留空格和换行符。