<?php

    $database_server = "localhost";
    $database_name = "remotecontrol";
    $database_user = "root";
    $database_password = "";

    $query_sql = "";

    $con = mysql_connect($database_server,$database_user,$database_password);
    if(!$con)
    {
        die("Could not connect: ".mysql_error());
    }

    mysql_select_db($database_name,$con);

    $query_sql = "SELECT data FROM power";

    $result = mysql_query($query_sql);
    while($row = mysql_fetch_array($result))
    {
        echo $row['data'];
    }

    mysql_close($con);
?>