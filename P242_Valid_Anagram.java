class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> map = new HashMap<>();
        int n1 = s.length();
        int n2 = t.length();
        if(n1 != n2) return false;
        for(int i = 0; i < n1; i++){
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        
        for(int i = 0; i < n2; i++){
            if(map.get(t.charAt(i)) == null) return false;
            else{
                char c = t.charAt(i);
                map.put(c, map.getOrDefault(c, 0) - 1);
                if(map.get(t.charAt(i)) < 0) return false;
            }
        }
        return true;
    }
}

//直接利用26字母的table
public boolean isAnagram(String s, String t) {
    if (s.length() != t.length()) {
        return false;
    }
    int[] counter = new int[26];
    for (int i = 0; i < s.length(); i++) {
        counter[s.charAt(i) - 'a']++;
        counter[t.charAt(i) - 'a']--;
    }
    for (int count : counter) {
        if (count != 0) {
            return false;
        }
    }
    return true;
}
