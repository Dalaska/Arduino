# linux notes

## 改alias
1. vi ~/.bashrc ===> 打开bash的配置文件
2. 输入alias 新命令='旧命令 -选项/参数' ===> 修改命令别名
3. source ~/.bashrc ===> 使得修改完的命令别名生效（“~”表示Web 应用程序根目录）
命令别名的增删改查都可以在.bashrc操作，注意不加空格alias ga='git add .'

深度学习环境配置
1. 安装anaconda
2. 打开Anaconda Prompt

3. 创建虚拟环境
conda create -n daruiig python=3.5
activate daruiig
4. 安装dependency
pip install keras==2.0.8 -i https://pypi.douban.com/simple/ 
pip install tensorflow==1.1 -i https://pypi.douban.com/simple/ 
(新版 keras 和 tensorflow会有代码兼容问题建议安装以上版本)
pip install opencv-python -i https://pypi.douban.com/simple/ 
5. 输入： jupyter notebook 打开编译器
6. 运行 Car_Detection.ipynb
