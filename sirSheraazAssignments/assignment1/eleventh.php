<?php 
echo "Eleventh<br>"; 
//Write a Program which should read text from file and display list of all sentences which have atleast two consecutive alphabets in it otherwise write sentence in another file. 

$fileRead = file("ReadFile.txt");
$lengthOfFileRead = count($fileRead);

for($i = 0; $i < $lengthOfFileRead; ++$i){
    // echo $i.". ".$fileRead[$i]."<br>";
    $lengthOfSentence = strlen($fileRead[$i]);
    $boolRepeatedAlphabets = false;
    for($j = 0; $j < $lengthOfSentence; ++$j){
        if(isset($fileRead[$i][$j+1]) && ord($fileRead[$i][$j])+1 == ord($fileRead[$i][$j+1])){
            $boolRepeatedAlphabets = true;
            echo $fileRead[$i]."<br>";
            break;
        }        
    } 
    if($boolRepeatedAlphabets == false){
        file_put_contents('test.txt', $fileRead[$i], FILE_APPEND);
        continue;
    }
    echo "<br>";
}
exit();