<?php 
echo "Second<br>"; 
//Write a function which should add the two vowels in the arrays and geenrate third array and store vowels only once if repeated  
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

function findVowelsSumRepeated($string1, $string2){
    $vowelString1 = findVowels($string1);
    $vowelString2 = findVowels($string2);
    $sumOfVowels = $vowelString1['used'].$vowelString2['used'];
    $lowerSumOfVowels = strtolower($sumOfVowels);
    // echo print_r($sumOfVowels)."<br>";
    $vowelsRepeated = NULL; 
    for($k = 0; $k < strlen($sumOfVowels); ++$k){
        $temp = $lowerSumOfVowels[$k];
        for($l = 0; $l < strlen($sumOfVowels); ++$l){
            if($lowerSumOfVowels[$k] == $lowerSumOfVowels[$l]){
                if($k != $l){
                    // echo "temp = ".$temp; echo "<br>";
                    // echo "current value = ".$sumOfVowels[$k]; echo "<br>";
                    $vowelsRepeated .= $lowerSumOfVowels[$k];
                    break;
                }
                
            }
        }    
    }
    $vowelsRepeated = count_chars($vowelsRepeated, 3);
    //Could not find any alternate complete functionality for removing duplicates, working on it.
    return array('sum' => $sumOfVowels, 'repeated' => $vowelsRepeated);
}

$string1 = "Virtual";
$string2 = "University";

$string3 = findVowelsSumRepeated($string1, $string2);
echo "<pre>";
echo print_r($string3);

exit();