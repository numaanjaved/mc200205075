<?php
    $host = 'localhost';
    $username = 'root';
    $password = '';
    $db = 'project';
    $mysql = new mysqli($host, $username, $password, $db);

    // $mysql->query("INSERT into user_roles (roles_name) VALUES ('admin')");
    // $mysql->query("INSERT into user_roles (roles_name) VALUES ('teacher')");
    // $mysql->query("INSERT into user_roles (roles_name) VALUES ('student')");
    //$mysql->query("INSERT into users (roles_id, username, password, status, approved_by) VALUES (1, 'admin', 'admin123', 1, 1)");

    include("login.html");