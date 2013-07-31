## gitdm配置文件生成方法 ##

**gitdm** 需要进行一些配置，才能更好的进行数据挖掘。

**gitdm**默认的配置文件为当前目录下的文件`gitdm.config`

一般`gitdm.config`需要进行以下配置

	EmailAliases	openstack-config/aliases
	EmailMap openstack-config/domain-map
	EmailMap openstack-config/email-map
    GroupMap openstack-config/groups/att AT&T
    GroupMap openstack-config/groups/bvox BVox
	FileTypeMap sample-config/filetypes.txt


`EmailAliases` 用于处理一个开发者有多个邮箱的情况。

`EmailMap`	用于将域名或者邮箱跟雇员公司对应起来，即说明某个开发者属于哪一个公司的。
其格式为

    [user@]domain  employer  [< yyyy-mm-dd]

`GroupMap` 对于不使用公司邮箱的开发者，也需要将其映射到一个具体的公司组织中。

`FileTypeMap` 用于对文件类型进行映射

### 1. 获取EmailAliases ###

运行如下命令，生成邮件别名文件`aliases`

    get-email-aliases.sh

### 2. 获取邮箱地址 ###

运行如下命令，得到`emails.txt`

    get-email-address.sh
    sed 's/ /\n/' < aliases >> tmp
    sed 's/ /\n/' < other-aliases >> tmp
    (sort | uniq | grep -v '\((none)\|\.local\)$') < tmp > emails.txt

### 3 根据`emails.txt`中的邮箱，得到`launchpad`中的名称 ###
	python launchpad/map-email-to-lp-name.py $(cat emails.txt) > launchpad-ids.txt



----------

**不想知道原理，直接使用的请看下面**：

# 分析步骤 #
## 1 获取邮件别名 ##
修改`get-email-aliases.sh`中的shell变量`GIT`和`PROJECTS`，使`GIT`指向所要分析代码的目录，`PROJECTS`
为所要分析的项目名称。然后运行如下命令：

    get-email-aliases.sh

得到文件`aliases`，将其拷贝到`foo-config`文件夹中。

    cp aliases	foo-config

## 2 拷贝配置文件到所要分析的目录 ##

    cp -r foo-config  $DEST/
    cp  gitdm.config  $DEST/
## 3 运行 gitdm 命令分析##

    git log -p -M | gitdm -u -x  output.cvs


## 注意 ##
文件夹`foo-config`中`domain-map`和`email-map`的更新方法，需要手工进行。

文件夹`foo-config/groups/`下的文件也需要手工进行更新。
