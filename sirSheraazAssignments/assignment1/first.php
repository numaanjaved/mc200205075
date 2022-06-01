<?php 
echo "First<br>"; 
//Write a program which should count Vowels in the strings and return vowels in reverse order if vowels are more than 3. 

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
function displayVowels($vowels){
    echo "Total Vowels in the Strings are ".$vowels['count']."<br>"; 
}
function reverseVowels($vowels){
    if($vowels['count'] > 3){
        echo "Total Count of Vowels is more than 3.<br>So, the reverse of all vowels used is given as ";
        for($j = $vowels['count'] - 1; $j > -1; --$j){
            echo $vowels['used'][$j];
        }    
    }
    else{
        echo "Total Count of Vowels is less than 3";
    }   
}

function actionOnVowels($vowels){
    displayVowels($vowels);
    reverseVowels($vowels);
}
function VowelsInString($strings){
    $vowels = findVowels($strings);
    actionOnVowels($vowels);
}
//Main Program
$strings = "VirtualUniversity";
VowelsInString($strings);

exit();