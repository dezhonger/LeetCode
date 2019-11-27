
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dezhonger on 2019/11/27
 *
 * @author dezhonger
 * @since 2019/11/27
 */
public class Leetcode1268 {

    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<List<String>> res = new ArrayList<>();
        if (products == null || products.length == 0) {
            return res;
        }
        Arrays.sort(products);
        int index = 0;
        int maxIndex = products.length;
        for (int i = 1; i <= searchWord.length(); i++) {
            String prefix = searchWord.substring(0, i);
            while (true) {
                if (index < maxIndex && products[index].length() >= i && products[index].substring(0, i).equals(prefix)) {
                    List<String> tmp = new ArrayList<>();
                    tmp.add(products[index]);
                    for (int j = index + 1; j <= index + 2 && j < maxIndex; j++) {
                        if (products[j].length() >= i && products[j].substring(0, i).equals(prefix)) {
                            tmp.add(products[j]);
                        }
                    }
                    res.add(tmp);
                    break;
                } else {
                    if (index == maxIndex - 1) {
                        res.add(new ArrayList<>());
                        break;
                    }
                    index++;

                }
            }
        }
        return res;
    }
}
