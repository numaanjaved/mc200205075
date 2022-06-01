<?php 
echo "Eightth<br>"; 
//Write a the function Word (sen) take the sen parameter being passed and return the largest word in the string. If there are two or more words that are the same length, return the first word from the string with that length. 


$string = "Virtual Sencatione tribulatin a good place to study";

function Word($sen){
    $words = explode(" ", $sen);
    $largestLengthOfWord = strlen($words[0]);
    $wordsLength = count($words);
    $largestWord = $words[0];

    for($i = 0; $i < $wordsLength; ++$i){
        $lengthOfWord[$i] = strlen($words[$i]);
        
        if($largestLengthOfWord < $lengthOfWord[$i]){
            $largestLengthOfWord = $lengthOfWord[$i];
            $largestWord = $words[$i];
        }
    }
    return $largestWord;
}

echo Word($string);

exit();