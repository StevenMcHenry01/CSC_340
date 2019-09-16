package com.StevenMcHenry.Sfsu.CSC340.Assignment1;

public enum PartsOfSpeech {
    ADVERB("[adverb]"),
    ADJECTIVE("[adjective]"),
    NOUN("[noun]"),
    CONJUNCTION("[conjunction]"),
    INTERJECTION("[interjection]"),
    PREPOSITION("[preposition]"),
    VERB("[verb]"),
    PRONOUN("[pronoun]");

    private String value;

    PartsOfSpeech(String env) {
        this.value = env;
    }

    public String getValue() {
        return value;
    }
}
