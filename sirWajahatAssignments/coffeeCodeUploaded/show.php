<?php
include("vendor/coffeecode/uploader/src/Uploader.php");
include("vendor/coffeecode/uploader/src/Image.php");

$image = new CoffeeCode\Uploader\Image("uploads", "images", 600);
if($_FILES){
    try{
        $upload = $image->upload($_FILES['image'], $_FILES['image']['name']);
        echo "<img src='{$upload}' width='100%'>";
    }
    catch(Exception $e){
        echo "<p>(!) {$e->getMessage()}</p>";        
    }
}