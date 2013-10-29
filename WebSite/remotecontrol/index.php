<?php
/**
 * Created by JetBrains PhpStorm.
 * User: geeknimo
 * Date: 13-9-9
 * Time: 下午5:24
 * To change this template use File | Settings | File Templates.
 */

    if(isset($_REQUEST['flag']))
    {
        $flag = $_REQUEST['flag'];

        if(isset($_REQUEST['line']))
        {
            $line = $_REQUEST['line'];
        }
        else
        {
            $line = "";
        }

        $database_server = "localhost";
        $database_name = "geeknimo_remotecontrol";
        $database_user = "geeknimo_geeks";
        $database_password = "hxjlzq1314";

        $con = mysql_connect($database_server,$database_user,$database_password);
        if(!$con)
        {
            die("Could not connect: ".mysql_error());
        }
        mysql_select_db($database_name,$con);

        $query_sql = "";

        switch($flag)
        {
            case '0':   // maybe for read
            {
                $query_sql = "SELECT line FROM jobs";

                $result = mysql_query($query_sql);
                while($row = mysql_fetch_array($result))
                {
                    echo $row['line'];
                }
            }
                break;

            case '1':   // maybe for write
            {
                if($line == 1)
                {
                    $query_sql = "UPDATE jobs SET line = '1' WHERE uid = '1'";
                }
                if($line == 2)
                {
                    $query_sql = "UPDATE jobs SET line = '2' WHERE uid = '1'";
                }

                if(mysql_query($query_sql))
                {
                    echo "ok";
                }
                else
                {
                    echo "make a mistake:".mysql_error();
                }
            }
                break;

            case '2':   // maybe for other thing.
            {
                echo "i think i can't do anything.";
            }
                break;

            default:    // default not anythink.
            {
                echo "hi,boy,what are u doing?";
            }
        }
        mysql_close($con);
    }
    else
        echo "hi,boy,what are u doing?";
?>