<?php
    $host = 'localhost';
    $username = 'root';
    $password = '';
    $db = 'project';
    $mysql = new mysqli($host, $username, $password, $db);
    unset($host, $username, $password, $db);
    // $mysql->query("INSERT into user_roles (role_name) VALUES ('admin')");
    // $mysql->query("INSERT into user_roles (role_name) VALUES ('teacher')");
    // $mysql->query("INSERT into user_roles (role_name) VALUES ('student')");
    //$mysql->query("INSERT into users (roles_id, username, password, status, approved_by) VALUES (1, 'admin', 'admin123', 1, NULL)");
    if($_POST){
        ?><pre> <?php

            $username = $_POST['username'];
            $password = $_POST['password'];

            $presentInDatabase = $mysql->query("SELECT * FROM users WHERE username = '".$username."' AND password = '".$password."'");
            if($presentInDatabase->num_rows != 0){
                
                $x = $presentInDatabase->fetch_assoc();
                $roles = $mysql->query("SELECT * FROM user_roles WHERE user_id = '".$x['id']."'");
                $role = $roles->fetch_assoc();
                if($role['role_id'] == 1){
                    echo "Welcome to the Admin Dashboard";
                }
                else if($role['role_id'] == 2){
                    echo "Welcome to the Teacher Dashboard";
                }
                else if($role['role_id'] == 3){
                    echo "Welcome to the Student Dashboard";
                }
                exit;
                // $_SESSION['login'] = 1;
                // $_SESSION['user'] 

            }
            else{
                echo "<div>username and password are not present in database</div>";
            }
        ?></pre> <?php
        
    }
    
    include("login.html");