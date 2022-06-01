<?php     
    $host = "localhost";
    $username = "root";
    $password = "";
    
    $connection = new mysqli($host, $username, $password);
    
    if($connection->connect_error){
        echo "Error in Database Connection";
    }
    else{
        $dbName = 'PHARMACY_DB';
        $myQuery = 'CREATE DATABASE '.$dbName;
        $statement = $connection->prepare($myQuery);
        $statement->execute();
    }