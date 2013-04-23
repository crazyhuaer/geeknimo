#!/bin/sh
#echo "hello"

#first_var=$1

#if [ $first_va!=" " ];then
#    echo "$1 exist."
#else
#    echo "$1 here?"
#fi

echo "this file is:"$1

$1="/etc/shells"
if [ -d $1 ]
then
    echo $1" is a dir and exist."
elif [ -e $1 ]
then
    echo $1" is a file and exist."
else
    echo "i don't know "$1" is what?"
    return
fi


if [ -r $1 ];then
    echo "$1 read."
    var=$(cat $1)
    echo $1" content is:"$var""
    #for index in $(cat /etc/shells)
    for index in $var
    do 
        echo "$index"
        line_count=`echo "$index"|wc -m`
        echo $index" count:"$line_count
        echo $i
    done

elif [ -w $1 ];then
    echo "$1 write."
else
    echo "i don't know"
fi
