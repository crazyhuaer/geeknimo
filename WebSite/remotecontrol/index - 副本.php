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
        $database_server = "localhost";
        $database_name = "remotecontrol";
        $database_user = "root";
        $database_password = "";

        $query_sql = "";

        switch($flag)
        {
            case '0':   // maybe for read
            {
                $con = mysql_connect($database_server,$database_user,$database_password);
                if(!$con)
                {
                    die("Could not connect: ".mysql_error());
                }

                mysql_select_db($database_name,$con);

                $query_sql = "SELECT line FROM power";

                $result = mysql_query($query_sql);
                while($row = mysql_fetch_array($result))
                {
                    /*if($row['line'] == 1)
                    {
                        echo $row['line'];
                    }
                    else if($row['line'] == 2)
                    {
                        echo $row['line'];
                    }
                    else
                    {
                        echo "0";
                    }*/
                    echo $row['line'];
                }

                mysql_close($con);
            }
                break;

            case '1':   // maybe for write
            {

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
    }
    else
        echo "hi,boy,what are u doing?";
?>