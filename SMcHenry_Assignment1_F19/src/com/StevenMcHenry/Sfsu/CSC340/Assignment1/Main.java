package com.StevenMcHenry.Sfsu.CSC340.Assignment1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        looper();
        System.out.println("\n-----THANK YOU-----");
    }

    public static void looper() {
        var d = new Dictionary();
        StringTokenizer tokenizer;
        BufferedReader input;
        ArrayList<String> expArray = new ArrayList<>();
        ArrayList<String> res = new ArrayList<>();
        try {
            while (true) {
                input = new BufferedReader(new InputStreamReader(System.in));
                System.out.print("Search: ");
                tokenizer = new StringTokenizer(input.readLine(), " ");

                // place tokens into an arrayList and make them lowercase
                while (tokenizer.hasMoreTokens()) {
                    expArray.add(tokenizer.nextToken().toLowerCase());
                }

                if (expArray.size() == 1) {
                    if (expArray.get(0).equals("!q")) {
                        return;
                    }
                    res = d.querryDictionary(expArray.get(0));
                }

                if (expArray.size() == 2) {
                    if (expArray.get(1).equals("distinct")) {
                        res = d.querryDictionary(expArray.get(0), true);
                    } else {
                        res = d.querryDictionary(expArray.get(0), expArray.get(1));
                    }
                }

                if (expArray.size() == 3) {
                    res = d.querryDictionary(expArray.get(0), expArray.get(1), true);
                }
                System.out.println("|");
                for (int i = 0; i < res.size(); i++) {
                    System.out.println(" " + res.get(i));
                }
                System.out.println("|");
                expArray.clear();
            }
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }
}
