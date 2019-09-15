package com.StevenMcHenry.Sfsu.CSC340.Assignment1;

public enum Definitions {
    DEF1("Familiar. Worked in Java."),
    DEF2("Unique. No duplicates. Clearly different or of a different kind."),
    DEF3("Uniquely. Written \"distinctly\"."),
    DEF4("A keyword in this assignment."),
    DEF5(" An advanced search option."),
    DEF6("Distinct is a parameter in this assignment."),
    DEF7("To be updated..."),
    DEF8("= C++ version of CSC210 + CSC220 + more."),
    DEF9("A CS upper division course."),
    DEF10("Many hours outside of class."),
    DEF11("Programming Methodology."),
    DEF12("Many hours outside of class."),
    DEF13("Ready to create complex data structures."),
    DEF14("To create data structures."),
    DEF15("A set of pages."),
    DEF16("A written work published in printed or electronic form."),
    DEF17("To arrange for someone to have a seat on a plane."),
    DEF18("To arrange something on a particular date."),
    DEF19("Adverb is a word that adds more information about place, time, manner, cause or\n" +
            "degree to a verb, an adjective, a phrase or another adverb."),
    DEF20("Adjective is a word that describes a person or thing, for example big, red and\n" +
            "clever in a big house, red wine and a clever idea."),
    DEF21("Interjection is a short sound, word or phrase spoken suddenly to express an\n" +
            "emotion. Oh!, Look out! and Ow! are interjections."),
    DEF22("Noun is a word that refers to a person, (such as Ann or doctor), a place (such as Paris\n" +
            "or city) or a thing, a quality or an activity (such as plant, sorrow or tennis."),
    DEF23("Here is one arrow: <IMG> -=>> </IMG>");

    private String value;

    Definitions(String env) {
        this.value = env;
    }

    public String getValue() {
        return value;
    }
}
