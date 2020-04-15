package com.netease.music.p20200416.leetcode65;

/**
 * Created by dezhonger on 2020/4/16
 * <p>
 * Leetcode65
 */
public class Leetcode0065 {
    public boolean isNumber(String s) {
        // write your code here
        if (s == null || s.trim().length() == 0 || s.trim().equals(".")) {
            return false;
        }
        Parser digit = new SAT(new IsDigit(), new Item());
        Parser sign = new SAT(new IsSign(), new Item());
        Parser dot = new Ch('.');
        Parser letterE = new Ch('e');
        Parser multiDigit = new Many(digit);
        Parser ePart = new And(letterE, new ZeroOrOne(sign), multiDigit);

        Parser validNumberRule1 = new And(new ZeroOrOne(sign), multiDigit, dot, multiDigit);
        Parser validNumberRule2 = new And(new ZeroOrOne(sign), multiDigit, ePart);
        Parser validNumberRule3 = new And(new ZeroOrOne(sign), multiDigit, dot, new ZeroOrOne(multiDigit), ePart);
        Parser validNumberRule4 = new And(new ZeroOrOne(sign), dot, multiDigit, new ZeroOrOne(ePart));
        Parser validNumberRule5 = new And(new ZeroOrOne(sign), multiDigit, new ZeroOrOne(dot));

        Parser validNumber = new Or(validNumberRule5, validNumberRule1, validNumberRule2, validNumberRule3, validNumberRule4);
        try {
            Result result = validNumber.parse(s.trim());
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    interface Predicate {
        boolean satisfy(String target);
    }

    interface Parser {
        Result parse(String target);
    }

    static class ZeroOrOne implements Parser {

        private Parser parser;

        public ZeroOrOne(Parser parser) {
            this.parser = parser;
        }

        @Override
        public Result parse(String target) {
            try {
                return parser.parse(target);
            } catch (Exception e) {
                //do nothing
            }
            return Result.buildResult("", target);
        }
    }

    static class Or implements Parser {

        private Parser[] parsers;

        public Or(Parser... parsers) {
            this.parsers = parsers;
        }

        @Override
        public Result parse(String target) {
            for (Parser parser : parsers) {
                try {
                    Result result = parser.parse(target);
                    if (result.remain.length() == 0) {
                        return result;
                    }
                } catch (Exception e) {
                    //do nothing
                }
            }
            throw new RuntimeException("OR Ignore Expect " + parsers + " parse " + target);
        }
    }

    static class Many implements Parser {

        private Parser parser;

        public Many(Parser parser) {
            this.parser = parser;
        }

        @Override
        public Result parse(String target) {
            Result result = parser.parse(target);
            try {
                while (result.remain.length() > 0) {
                    result = Result.concat(result, parser.parse(result.remain));
                }
            } catch (Exception e) {
                //do nothing
            }
            return result;
        }
    }

    static class Item implements Parser {
        @Override
        public Result parse(String target) {
            return Result.buildResult(target.substring(0, 1),
                    target.substring(1));
        }
    }

    static class And implements Parser {

        private Parser[] parsers;

        public And(Parser... parsers) {
            this.parsers = parsers;
        }

        @Override
        public Result parse(String target) {
            Result result = Result.buildResult("", target);
            for (Parser parser : parsers) {
                result = Result.concat(result, parser.parse(result.remain));
            }
            return result;
        }
    }

    static class SAT implements Parser {

        private Predicate predicate;
        private Parser parser;

        public SAT(Predicate predicate, Parser parser) {
            this.predicate = predicate;
            this.parser = parser;
        }

        @Override
        public Result parse(String target) {
            Result result = parser.parse(target);
            if (predicate.satisfy(result.recognized))
                return result;
            throw new RuntimeException("parse error: " + parser + " " + predicate + " parse " + target + " fail");
        }
    }

    static class Result {
        private String recognized;
        private String remain;

        static Result buildResult(String recognized, String remain) {
            Result result = new Result();
            result.recognized = recognized;
            result.remain = remain;
            return result;
        }

        static Result concat(Result result1, Result result2) {
            return Result.buildResult(result1.recognized + result2.recognized, result2.remain);
        }

        @Override
        public String toString() {
            return "recognized: " + recognized + " remain: " + remain;
        }
    }

    static class IsSign implements Predicate {
        @Override
        public boolean satisfy(String target) {
            return target.charAt(0) == '+' || target.charAt(0) == '-';
        }
    }

    static class Ch implements Parser {

        private char c;

        public Ch(char c) {
            this.c = c;
        }

        @Override
        public Result parse(String target) {
            Item item = new Item();
            Result result = item.parse(target);
            if (String.valueOf(c).equals(result.recognized)) {
                return result;
            }
            throw new RuntimeException("parser error: Ch parser " + c + " parse error");
        }
    }

    static class IsDigit implements Predicate {

        @Override
        public boolean satisfy(String target) {
            return target.charAt(0) >= '0' && target.charAt(0) <= '9';
        }
    }
}
