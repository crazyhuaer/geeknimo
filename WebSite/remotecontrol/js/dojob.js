/**
 * Created with JetBrains PhpStorm.
 * User: geeknimo
 * Date: 13-9-10
 * Time: 下午5:13
 * To change this template use File | Settings | File Templates.
 */
$(document).ready(function() {

    $("#current_status").click(function(){

        $.ajax({
            url:'index.php',
            type:'post',
            data:'flag=0',
            async : false,
            error:function(){
                alert('error');
            },
            success:function(data){
                if(data == "1")
                {
                    alter("当前模式工作在:晚上，一个风扇");
                }
                if(data == "2")
                {
                    alter("当前模式工作在:白天，两个风扇");
                }
            }
        });
    });


    $("#update_day").click(function(){

        $.ajax({
            url:'index.php',
            type:'post',
            data:'flag=1&line=2',
            async : false,
            error:function(){
                alert('error');
            },
            success:function(data){
                if(data == "ok")
                {
                    alert("已经切换到白天模式");
                }
            }
        });
    });


    $("#update_night").click(function(){

         $.ajax({
             url:'index.php',
             type:'post',
             data:'flag=1&line=1',
             async : false,
             error:function(){
             alert('error');
             },
             success:function(data){
                 if(data == "ok")
                 {
                     alert("已经切换到晚上模式");
                 }
             }
         });
     });
});