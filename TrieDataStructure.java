import java.util.ArrayList;

class Trie {
  boolean EOW;
  Trie[] alphabets;

  Trie() {
    alphabets = new Trie[26];
    EOW = false;
  }
}

class TrieStringBuilder {
  Trie root = null;
  Trie node = new Trie();

  public void buildString(String chars) {
    char[] ch = chars.toCharArray();
    int i = 0;
    int threshold = ch.length - 1;
    if (root == null) {
      while (i < ch.length) {
        Trie child = new Trie();
        int charIndex = (ch[i] - '0') - 49;
        node.alphabets[charIndex] = child;
        if (i == threshold)
          child.EOW = true;
        if (root == null)
          root = node;
        node = child;
        i++;
      }
    } else {
      Trie r = new Trie();
      r = root;
      while (i < ch.length) {
        int charIndex = (ch[i] - '0') - 49;
        if (r.alphabets[charIndex] != null)
          r = r.alphabets[charIndex];
        else {
          Trie child = new Trie();
          r.alphabets[charIndex] = child;
          if (i == threshold)
            child.EOW = true;
          r = child;
        }
        i++;
      }
    }
  }

  public void recFn(Trie x, StringBuilder sb, boolean rStatus, String searching, int build, ArrayList<String> list) {

    if (rStatus) {
      if (x.EOW)
        list.add(sb.toString());

      for (int i = 0; i < 26; i++) {
        if (x.alphabets[i] != null) {
          // System.out.println((char) (i + 49 + '0'));
          sb.append((char) (i + 49 + '0'));
          recFn(x.alphabets[i], sb, rStatus, "", build, list);
          sb.deleteCharAt(sb.length() - 1); // Back-tracking
        }
      }
    } else {
      int i = searching.charAt(0);
      int j = 1;
      while (j < searching.length() && x.alphabets[i - '0' - 49] != null) {
        x = x.alphabets[i - '0' - 49];
        i = searching.charAt(j++);
      }
      recFn(x.alphabets[i - '0' - 49], sb, true, "", build, list);
    }
  }

  public void retrievStrings() {
    Trie r = new Trie();
    r = root;
    ArrayList<String> l = new ArrayList<>();
    recFn(r, new StringBuilder(), true, "", 0, l);
    System.out.println(l);
  }

  public ArrayList<String> search(String searching) {
    Trie r = new Trie();
    r = root;
    ArrayList<String> l = new ArrayList<>();
    recFn(r, new StringBuilder(), false, searching, 1, l);
    for (int i = 0; i < l.size(); i++)
      l.set(i, searching + "" + l.get(i));
    return l;
  }
}

public class TrieDataStructure {
  public static void main(String[] args) {

    TrieStringBuilder tsb = new TrieStringBuilder();

    tsb.buildString("app");
    tsb.buildString("bye");
    tsb.buildString("apple");
    tsb.buildString("apply");
    tsb.buildString("ball");
    tsb.buildString("mobile");
    tsb.buildString("mouse");
    tsb.buildString("moneypot");
    tsb.buildString("monitor");
    tsb.buildString("mousepad");

    tsb.retrievStrings();

    ArrayList<String> results = tsb.search("appl");
    System.out.println(results);
  }
}