% 4_1 - Grade Calculator
canContinue = true;
while canContinue
    score = input("Enter Score: ");
    if(score >= 90 && score <= 100)
        disp("Grade: A");
    elseif(score >= 80 && score < 90)
        disp("Grade: B");
    elseif(score >= 70 && score < 80)
        disp("Grade: C");
    elseif(score >= 60 && score < 70)
        disp("Grade: D");
    elseif(score >= 50 && score < 60)
        disp("Grade: E");
    else
        disp("Grade: F");
    end
    loop = input("Do you want to add more scores? (Y/N): ", "s");
    if(loop == "Y")
        canContinue = true;
    else
        canContinue = false;
    end
end
