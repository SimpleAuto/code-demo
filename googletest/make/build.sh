#!/usr/bin/env bash
########################################################################
#    File Name: build.sh
# 
#       Author: Thomas Shanghai,Inc.
#         Mail: 982737593@qq.com
# Created Time: 2018年04月04日 星期三 00时02分02秒
#  Description: ...
# 
########################################################################

echo -e "\033[31m mkdir obj \033[0m"
mkdir obj 
echo -e "\033[31m mkdir bin   \033[0m"
mkdir bin
echo -e "\033[31m make \033[0m" "\033[32m [BEGIN] \033[0m"
make -j8
echo -e "\033[31m make \033[0m" "\033[32m [END] \033[0m"
mv *.o *.a obj/
