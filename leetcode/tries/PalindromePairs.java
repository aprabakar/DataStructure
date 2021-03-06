// http://www.allenlipeng47.com/blog/index.php/2016/03/15/palindrome-pairs/

public static class Trie {
    int pos;
    Trie[] nodes;   // consider xyxabc. if current trie is 'a'. Then a.nodes has information. It means string after a is palindrome
    List<Integer> palins;
    public Trie() {
        pos = -1;
        nodes = new Trie[26];
        palins = new ArrayList<>();
    }
}

public static void add(Trie root, String word, int pos) {
    for (int i = word.length() - 1; i >= 0; i--) {
        char ch = word.charAt(i);
        if (isPalindrome(word, 0, i)) { // check if substring(0, i) is palindrome.
            root.palins.add(pos);
        }
        if (root.nodes[ch - 'a'] == null) {
            root.nodes[ch - 'a'] = new Trie();
        }
        root = root.nodes[ch - 'a'];
    }
    root.pos = pos; // if it is xyxcba. Until now, the node should be at x.
    root.palins.add(pos);
}

public static void search(Trie root, String[] words, int i, List<List<Integer>> ans) {
    int len = words[i].length();
    for (int j = 0; j < len && root != null; j++) {
        if (root.pos >= 0 && i != root.pos && isPalindrome(words[i], j, len - 1)) {
            ans.add(Arrays.asList(new Integer[] {i, root.pos}));
        }
        char ch = words[i].charAt(j);
        root = root.nodes[ch - 'a'];
    }
    if (root != null && root.palins.size() > 0) { // assume 'xyxabc' is in trie, now try 'cba'
        for (int j : root.palins) {
            if (j != i) {
                ans.add(Arrays.asList(new Integer[] {i, j}));
            }
        }
    }
}

public static List<List<Integer>> palindromePairs(String[] words) {
    List<List<Integer>> ans = new ArrayList<>();
    Trie trie = new Trie();
    for (int i = 0; i < words.length; i++) {
        add(trie, words[i], i);
    }
    for (int i = 0; i < words.length; i++) {
        search(trie, words, i, ans);
    }
    return ans;
}

public static boolean isPalindrome(String str, int i, int j) {
    while (i < j) {
        if (str.charAt(i++) != str.charAt(j--)) {
            return false;
        }
    }
    return true;
}
