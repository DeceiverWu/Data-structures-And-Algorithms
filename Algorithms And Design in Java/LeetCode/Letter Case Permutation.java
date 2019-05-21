/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

Note:
1.S will be a string with length between 1 and 12.
2.S will consist only of letters or digits.

*/

class Solution {

    public List<String> letterCasePermutation(String S) {
        if (S == null) {
            return new LinkedList<>();
        }

        Queue<String> queue = new LinkedList<>();
        queue.offer(S);
        
        for (int i = 0; i < S.length(); i++) {
            if (Character.isDigit(S.charAt(i)))
                continue;
            int size = queue.size();
            for (int j = 0; j < size; j++) {
                String cur = queue.poll();
                ch[] ch = cur.toCharArray();

                ch[i] = Character.toUpperCase(ch[i]);
                queue.offer(String.valueOf(ch));

                ch[i] = Character.toLowerCase(ch[i]);
                queue.offer(String.valueOf(ch));
            }
        }

        return new LinkedList<>(queue);
    }

}

class Solutions {

    public List<String> letterCasePermutation(String S) {
        if (S == null) {
            return new LinkedList<>();
        }

        List<String> ans = new LinkedList<>();
        letterCasePermutation(ans, S.toCharArray(), 0);
        
        return ans;
    }

    private void letterCasePermutation(List<String> ans, char[] ch, int index) {
        if (index == ch.length) {
            ans.add(new String(ch));
            return;
        }
        if (ch[index] >= '0' && ch[index] <= '9') {
            letterCasePermutation(ans, ch, index + 1);
            return;
        }

        ch[index] = Character.toUpperCase(ch[index]);
        letterCasePermutation(ans, ch, index + 1);

        ch[index] = Character.toLowerCase(ch[index]);
        letterCasePermutation(ans, ch, index + 1);
    }
}
