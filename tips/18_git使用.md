## 如何用 git 优雅提交

快速理解上手 [](https://www.runoob.com/manual/git-guide/)

### 从零开始

1. 在 GitHub 创建一个仓库

值得注意的是，注意不要勾选 "Initialize this repository with a README"，保持仓库完全空白  
并且创建仓库步骤是不可或缺的，因为 git 不借助其他无法通过命令行创建仓库  

2. 本地初始化仓库

```shell
# 进入文件夹
cd "你的文件夹路径"
# 1. 初始化本地仓库（让这个文件夹受 Git 管理）
git init
# 2. 将文件夹内的所有文件添加到暂存区
git add .
# 3. 提交到本地仓库，并添加备注信息
git commit -m "first commit"
```

3. 建立本地与 GitHub 的连接

```shell
# 4. 指定主分支名为 main (GitHub 现在默认使用 main)
git branch -M main
# 5. 将本地仓库关联到 GitHub 远程仓库
git remote add origin https://github.com/用户名/仓库名.git
# 6. 将本地代码推送到 GitHub
git push -u origin main
```

### 后续提交

```shell
# 0. 查看修改状态 (可选)
git status
# 1. 将修改添加到“暂存区” (add)
git add .
# 2. 提交到“本地仓库” (commit)
git commit -m "update ..."
# 3. 同步到 GitHub“远程仓库” (Push)
git push 
```

### 更新状态

```shell
git pull origin main
```

在实际操作中，可以直接使用 `git pull`，前者是全称，后者是简称

- `origin`：远程仓库的绰号，在第一次 `git clone` 或 `remote add` 时，Git 默认把那个 GitHub 地址命名为 origin
- `main`：远程仓库里的分支名称


### 远程克隆仓库

```shell
git clone https://github.com/username/reponame.git
```

需要注意的是，git 会在当前目录下创建一个与仓库同名的文件夹，如果已经建好，可以指定位置，比如在末尾加 `.`

并且，不需要提前 **init**

因为 `git clone` 的本质是 **一键全包** 服务，执行 `git clone` 时，Git 会自动完成
- 创建文件夹（以仓库名命名）
- 初始化：在那个文件夹里自动运行 git init
- 建立连接：自动运行 git remote add origin <URL>
- 下载数据：把远程的所有文件和历史记录拉取下来
- 同步分支：自动把你的本地分支指向远程的 main