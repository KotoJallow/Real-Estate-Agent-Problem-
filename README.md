# Real-Estate-Agent-Problem
    
    
    A real estate agent routes his customers to houses and meets them to houseowners. Then he
    wants tenants to sort the houses according to their likes. He also wants houseowners to sort
    the tenants which they want to give their house most. After that, he assigns the tenants to
    houses considering their preferences to make them all satisfied. He is primarily considering
    the preferences of houseowners. He graduate from university as a software engineer but
    works as a real estate agent. So, he uses Gale Shapley algorithm to rent the houses to satisfy
    both houseowners and tenants. 
    
# Coding details:


    # 1.
    Number of tenants is equal to the number of houses. Each houseowner has only one
    house so that while tenants are sorting the houses it means they are sorting the
    houseowners.
    #2.
    We give 2 seperate files including tenant preferences and houseowner preferences.
    These files are named as “evsahibitercihi.txt” and “kiracitercihi.txt”. First you have to
    read these files in your code to get the preferences. 
  
    #3.
    File formats are like below (Sample files are given in the attachment). You can see 3
    tenants and 3 houseowners preferences below.
    evsahibitercihi.txt: (File is seperated by tabs. Each line represents a houseowner.
    They sorted the tenants they want most.)
            0 1 2
            1 0 2
            0 1 2

    If we explain this file, 0th householder wants to give his house to 0th tenant most, to
    1st tenant if not, to 2nd tenant if also not. 1st householder wants to give his house to
    1st tenant most, to 0th tenant if not, to 2nd tenant if also not. 3rd householder wants to
    give his house to 0th tenant most, to 1st tenant if not, to 2nd tenant if also not.
    kiracitercihi.txt: (File is seperated by tabs. Each line represents a tenant. They sorted
    the houses (so houseowners) they want most.)
            1 0 2
            0 1 2
            0 1 2
            
    If we explain this file, 0th tenant wants to rent 1st house most, to 0th house if not, to
    2nd house if also not. 1st tenant wants to rent 0th house most, to 1st house if not, to
    2nd house if also not. 3rd tenant wants to rent 0th house most, to 1st house if not, to
    2nd house if also not.
   
   Enjoy!!!

Suggestions comments and critisms are welcomed.

kotojalloh.kj@gmail.com

Istanbul Sabahattin Zaim University

Software Engineering

Class 2

Istanbul,Turkey.
