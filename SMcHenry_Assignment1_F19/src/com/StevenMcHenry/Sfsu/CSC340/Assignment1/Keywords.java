package com.StevenMcHenry.Sfsu.CSC340.Assignment1;

public enum Keywords {
    ARROW("Arrow"),
    DISTINCT("Distinct"),
    PLACEHOLDER("Placeholder"),
    CSC340("CSC340"),
    CSC220("CSC220"),
    BOOK("Book"),
    BOOKABLE("Bookable"),
    ADVERB("Adverb"),
    ADJECTIVE("Adjective"),
    INTERJECTION("Interjection"),
    NOUN("Noun");

    private String value;

    Keywords(String env) {
        this.value = env;
    }

    public String getValue() {
        return value;
    }
}
