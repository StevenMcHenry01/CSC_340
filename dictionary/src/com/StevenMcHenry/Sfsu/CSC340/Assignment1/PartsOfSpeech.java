package com.StevenMcHenry.Sfsu.CSC340.Assignment1;

public enum PartsOfSpeech {
    ADVERB("Adverb"),
    ADJECTIVE("Adjective"),
    NOUN("Noun"),
    CONJUNCTION("Conjunction"),
    INTERJECTION("Interjection"),
    PREPOSITION("Preposition"),
    VERB("Verb"),
    PRONOUN("Pronoun");

    private String value;

    PartsOfSpeech(String env) {
        this.value = env;
    }

    public String getValue() {
        return value;
    }
}
