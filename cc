import java.util.*;

public class Solution {
    public static String rearrangeWordsByVowelCount(String input) {
        String[] words = input.split(" ");
        Arrays.sort(words, Comparator.comparingInt(word -> {
            int count = 0;
            for (char c : word.toLowerCase().toCharArray()) {
                if ("aeiou".indexOf(c) != -1) count++;
            }
            return count;
        }));
        return String.join(" ", words);
    }

    public static List<Integer> removeConsecutiveDuplicates(List<Integer> arr) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < arr.size(); i++) {
            if (i == 0 || !arr.get(i).equals(arr.get(i - 1))) {
                result.add(arr.get(i));
            }
        }
        return result;
    }

    public static String findNthDayOfYear(int n, int year) {
        int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String[] months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) days[1] = 29;
        int month = 0;
        while (n > days[month]) n -= days[month++];
        return String.format("%02d %s, %d", n, months[month], year);
    }

    public static String coinDistribution(int amount) {
        int[] coins = {100, 50, 20, 10, 5, 1};
        StringBuilder output = new StringBuilder();
        for (int coin : coins) {
            if (amount >= coin) {
                output.append(amount / coin).append(" x ").append(coin).append(", ");
                amount %= coin;
            }
        }
        return output.length() > 0 ? output.substring(0, output.length() - 2) : "";
    }

    public static void main(String[] args) {
        System.out.println(rearrangeWordsByVowelCount("Programming is a fun activity"));
        List<Integer> inputList = Arrays.asList(1, 2, 2, 3, 3, 3, 4, 5, 5);
        System.out.println(removeConsecutiveDuplicates(inputList));
        System.out.println(findNthDayOfYear(100, 2024));
        System.out.println(coinDistribution(278));
    }
}
