class Solution {
    public boolean isPalinSent(String s) {
        StringBuilder res = new StringBuilder();
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            char ch = s.charAt(i);
            if (Character.isLetterOrDigit(ch)) {
                res.append(Character.toLowerCase(ch));
            }
        }

        StringBuilder org = new StringBuilder();
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (Character.isLetterOrDigit(ch)) {
                org.append(Character.toLowerCase(ch));
            }
        }

        return org.toString().equals(res.toString());
    }
}

