package com.StevenMcHenry.Sfsu.CSC340.Assignment1;

import com.google.common.collect.ArrayListMultimap;
import com.google.common.collect.ListMultimap;
import com.google.common.collect.Multimap;

import java.util.ArrayList;


/**
 *
 * @author Steven McHenry:
 *
 * Feel Free to describe your program here, but don't forget about the write up
 *
 *
 */
public class Dictionary {

    private static Multimap<String, String> multimap = ArrayListMultimap.create();
    static {
        multimap.put(Keywords.ARROW.getValue(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF23.getValue());
        multimap.put(Keywords.ARROW.getValue(), PartsOfSpeech.NOUN.getValue() + " : " + Definitions.DEF23.getValue());
        multimap.put(Keywords.BOOK.getValue(), PartsOfSpeech.VERB.getValue() + " : " + Definitions.DEF2.getValue());
        System.out.println(multimap.keys());
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
    public static ArrayList<String> querryDictionary(String word, String speechType, boolean distinct) {

        // add implementation here

        return null; // make sure to return the correct data
    }



}
