class Solution {
    public ArrayList<Integer> asciirange(String s) {
        int n = s.length();
        int[] arr = new int[n];
        arr[0] = (int)(s.charAt(0));
        for(int i =1; i < n; i++) {
            arr[i] = arr[i-1] + (int)(s.charAt(i));
        }
        // System.out.println(Arrays.toString(arr));
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i =0; i < n; i++) {
            int lastIndex = s.lastIndexOf(s.charAt(i));
            int firstIndex = s.indexOf(s.charAt(i));
            if(firstIndex != lastIndex && firstIndex + 1 != lastIndex && i == lastIndex) {
                ans.add(arr[i] - (arr[firstIndex] + (int)(s.charAt(i))));
            }
        }
        return ans;
    }
}