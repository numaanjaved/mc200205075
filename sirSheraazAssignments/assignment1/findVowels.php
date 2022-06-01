<?php
//Internal Functions 
function findVowels($strings){
    $vowels  = array(
        'a', 'e', 'i', 'o', 'u'
    );
    $vowelsUsed = NULL; 
    $lowerString = strtolower($strings);
    $lengthOfString = strlen($strings);

    $vowelCount = 0;
    for($i = 0; $i < $lengthOfString; ++$i){
        foreach($vowels as $vowel){
            if($lowerString[$i] == $vowel){
                $vowelsUsed .= $strings[$i];
                ++$vowelCount;
            } 
        }    
    }
    return array('used' => $vowelsUsed,'count' => $vowelCount);
}