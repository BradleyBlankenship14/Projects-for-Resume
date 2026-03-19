# -*- coding: utf-8 -*-
"""
Bradley Blankenship

Royal Flush Checker
"""
import random as r 
# build card decks / create a list manually
def CreateDeck():
# list of card suits
    cardSuit = ["S", "C", "H", "D"]

# list of card numbers
    cardNumber = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]

# empty list to store the deck into
    deck = []

# use for loop to combine ranks and suits and store them into a list
    for suit in cardSuit:
            for num in cardNumber:
                card = num + suit
                deck.append(card)
    return (deck)
# ask user for input of number of trials

def IsRoyal(hand):
    
    # declares list for royal flushes

    royalFlushH = ["AH", "KH", "QH", "JH", "10H"] 
    royalFlushS = ["AS", "KS", "QS", "JS", "10S"]
    royalFlushC = ["AC", "KC", "QC", "JC", "10C"] 
    royalFlushD = ["AD", "KD", "QD", "JD", "10D"]

# sets a list of the royal flushes to check

    royalFlushes = [royalFlushH, royalFlushS, royalFlushC, royalFlushD] 
 
    # for loop to check for royal flushes uses boolean to exit
    for rf in royalFlushes:
        if set(rf) <= set(hand):
           return True
    return False
           
def main():
    # calls other function to create deck
    deck = CreateDeck()
    
    # ask user for amount of trials
    userTrials = int(input("Enter the amount of hands/trials you want to play so I can check how many times you get a royal flush: "))

    # royal flush count holder for increment
    royalFlushCount = 0
    
    # write for loop for monte carlo simulation
    for idx in range(userTrials):
        # deal a hand of 7 cards
        hand = r.sample(list(deck), 7)
        
        # check if the hand contains a royal flush by calling IsRoyal function
        if IsRoyal(hand):
            royalFlushCount += 1
  
    # calculates royal flush percent
    royalFlushPercent = (royalFlushCount / userTrials) * 100
    
    # print statements to print the final results
    print("You had " + str(royalFlushCount) + " royal flushes in " + str(userTrials) + " hands!")
    print("The percentage of royal flushes that you had is " + str(royalFlushPercent) + "%")
    
main()

