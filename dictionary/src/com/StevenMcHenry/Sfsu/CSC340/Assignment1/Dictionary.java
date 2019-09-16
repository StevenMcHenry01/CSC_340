package com.StevenMcHenry.Sfsu.CSC340.Assignment1;

import com.google.common.collect.ArrayListMultimap;
import com.google.common.collect.ListMultimap;
import com.google.common.collect.Multimap;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collection;


/**
 *
 * @author Steven McHenry:
 *
 * Feel Free to describe your program here, but don't forget about the write up
 *
 *
 */
public class Dictionary {

    private static ArrayList<String> result = new ArrayList<>();
    private static ArrayList<String> temp = new ArrayList<>();
    private static final ArrayList<String> speechTypes = new ArrayList<>();
    private static Multimap<String, String> multimap = ArrayListMultimap.create();
    // load all data into multimap and arrayList the first time a Dictionary object is created
    static {
        System.out.println("! Loading data...");
        multimap.put(Keywords.ARROW.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF23.getValue());
        multimap.put(Keywords.DISTINCT.name(), PartsOfSpeech.ADJECTIVE.getValue() + " : " + Definitions.DEF1.getValue());
        multimap.put(Keywords.DISTINCT.name(), PartsOfSpeech.ADJECTIVE.getValue() + " : " + Definitions.DEF2.getValue());
        multimap.put(Keywords.DISTINCT.name(), PartsOfSpeech.ADVERB.getValue() + " : " + Definitions.DEF3.getValue());
        multimap.put(Keywords.DISTINCT.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF4.getValue());
        multimap.put(Keywords.DISTINCT.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF4.getValue());
        multimap.put(Keywords.DISTINCT.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF4.getValue());
        multimap.put(Keywords.DISTINCT.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF5.getValue());
        multimap.put(Keywords.DISTINCT.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF6.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.ADJECTIVE.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.ADJECTIVE.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.ADVERB.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.CONJUNCTION.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.INTERJECTION.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.PREPOSITION.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.PRONOUN.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.PLACEHOLDER.name(), PartsOfSpeech.VERB.getValue() + " : " + Definitions.DEF7.getValue());
        multimap.put(Keywords.CSC340.name(), PartsOfSpeech.ADJECTIVE.getValue() + " : " + Definitions.DEF8.getValue());
        multimap.put(Keywords.CSC340.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF9.getValue());
        multimap.put(Keywords.CSC340.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF10.getValue());
        multimap.put(Keywords.CSC340.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF11.getValue());
        multimap.put(Keywords.CSC220.name(), PartsOfSpeech.ADJECTIVE.getValue() + " : " + Definitions.DEF13.getValue());
        multimap.put(Keywords.CSC220.name(), PartsOfSpeech.VERB.getValue() + " : " + Definitions.DEF14.getValue());
        multimap.put(Keywords.CSC220.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF24.getValue());
        multimap.put(Keywords.BOOK.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF15.getValue());
        multimap.put(Keywords.BOOK.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF16.getValue());
        multimap.put(Keywords.BOOK.name(), PartsOfSpeech.VERB.getValue() + " : " + Definitions.DEF17.getValue());
        multimap.put(Keywords.BOOK.name(), PartsOfSpeech.VERB.getValue() + " : " + Definitions.DEF18.getValue());
        multimap.put(Keywords.ADVERB.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF19.getValue());
        multimap.put(Keywords.ADJECTIVE.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF20.getValue());
        multimap.put(Keywords.INTERJECTION.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF21.getValue());
        multimap.put(Keywords.NOUN.name(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF22.getValue());
        multimap.put(Keywords.BOOKABLE.name(), PartsOfSpeech.ADJECTIVE.getValue() + " : " + Definitions.DEF25.getValue());
        speechTypes.add("adjective");
        speechTypes.add("noun");
        speechTypes.add("verb");
        speechTypes.add("adverb");
        speechTypes.add("pronoun");
        speechTypes.add("preposition");
        speechTypes.add("interjection");
        speechTypes.add("conjunction");
        System.out.println("! Loading completed...");
        System.out.println("\n-----DICTIONARY 340 JAVA-----\n");
    }

    /**
     * Process dictionary querry data and returns meaningful data
     *
     * @param word
     *            the word to be processed or null
     * @param speechType
     *            The SpeechType to check or null
     * @param distinct
     *            boolean whether or not to remove duplicates
     * @return
     *            an ArrayList of Strings where each entry is properly formatted for output
     *            EX: for a word named "word" ["word [PartOfSpeech1] Definition1", "word [PartOfSpeech2] Definition2"]
     *                for a word not in the Dictionary_Template ["none"]
     *
     *
     */
    public static ArrayList<String> querryDictionary(String word) {
        return getMatches(word);
    }

    public static ArrayList<String> querryDictionary(String word, boolean distinct) {
        result = getMatches(word);
        if (distinct == true) {
            result = removeDuplicates(result);
        }
        return result;
    }

    public static ArrayList<String> querryDictionary(String word, String speechType) {
        result = getMatches(word);
        return findSpeechType(result, speechType);
    }
    public static ArrayList<String> querryDictionary(String word, String speechType, boolean distinct) {
        if (word == null) {
            temp.add("<Not found>");
            return temp;
        }
        result = getMatches(word);
        if (speechType != null) {
            result = findSpeechType(result, speechType);
        }
        if (distinct == true) {
            result = removeDuplicates(result);
        }
        return result;
    }

    public static ArrayList<String> getMatches(String check) {
        check = check.toLowerCase();
        ArrayList<String> temp = new ArrayList<>(multimap.get(check.toUpperCase()));
        String key;
        if (check.contains("csc")) {
            key = check.toUpperCase();
        } else {
            key = check.substring(0, 1).toUpperCase() + check.substring(1);
        }
        if (temp.size() == 0) {
            temp.add("<Not found>");
            return temp;
        } else {
            for(int i = 0; i < temp.size(); i++) {
                temp.set(i, key + " " + temp.get(i));
            }
            return temp;
        }
    }

    public static ArrayList<String> removeDuplicates(ArrayList<String> initialList)
    {
        // Create a new ArrayList
        ArrayList<String> newList = new ArrayList<>();

        // iterate over initial
        for (String element : initialList) {
            if (!newList.contains(element)) {
                newList.add(element);
            }
        }
        return newList;
    }

    public static ArrayList<String> findSpeechType(ArrayList<String> initialList, String speechType)
    {
        // Create a new ArrayList
        ArrayList<String> newList = new ArrayList<>();
        if (!speechTypes.contains(speechType)) {
            newList.add("<2nd argument must be part of speech or \"distinct\">");
            return newList;
        }
        // iterate over initial
        for (String element : initialList) {
            for(String word: element.split(" ")) {
                if(word.trim().equals("[" + speechType + "]")) {
                    newList.add(element);
                }
            }
        }
        if (newList.size() == 0) {
            newList.add("<Not found>");
        }
        return newList;
    }



}
