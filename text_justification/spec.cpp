#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    vector<string> words;
    int maxWidth;
    vector<string> result;

    void InputFormat() {
        LINE(words % SIZE());
        LINE(maxWidth);
    }

    void OutputFormat() {
        LINES(result);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= words.size() && words.size() <= 300);
        CONS(1 <= maxWidth && maxWidth <= 100);
        CONS(eachWordValidLength(words, maxWidth));
    }

private:
    bool eachWordValidLength(const vector<string>& words, int maxWidth) {
        for (const string& word : words) {
            if (word.size() > maxWidth) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "This is an example of text justification.",
            "16"
        });
        Output({
            "This    is    an",
            "example  of text",
            "justification.  "
        });
    }

    void SampleTestCase2() {
        Input({
            "What must be acknowledgment shall be",
            "16"
        });
        Output({
            "What   must   be",
            "acknowledgment  ",
            "shall be        "
        });
    }

    void SampleTestCase3() {
        Input({
            "Science is what we understand well enough to explain to a computer. Art is everything else we do",
            "20"
        });
        Output({
            "Science  is  what we",
            "understand      well",
            "enough to explain to",
            "a  computer.  Art is",
            "everything  else  we",
            "do                  "
        });
    }

    void BeforeTestCase() {
        words.clear();
        result.clear();
    }

    void TestGroup1() {
        CASE(words = {"a", "b", "c", "d"}, maxWidth = 1);
        CASE(words = {"hello", "world"}, maxWidth = 10);
        CASE(words = {"one", "longword", "word"}, maxWidth = 10);
    }

    void TestGroup2() {
        CASE(words = {"a", "b", "c", "d"}, maxWidth = 4);
        CASE(words = {"short", "words", "only"}, maxWidth = 6);
        CASE(words = {"singleword"}, maxWidth = 20);
    }

    void TestGroup3() {
        CASE(words = generateRandomWords(10, 20), maxWidth = 15);
        CASE(words = generateRandomWords(300, 1), maxWidth = 5);
        CASE(words = generateRandomWords(200, 20), maxWidth = 100);
    }

    void TestGroup4() {
        CASE(words = {"longword"}, maxWidth = 9);
        CASE(words = {"edgecase"}, maxWidth = 8);
        CASE(words = generateRandomWords(300, 10), maxWidth = 50);
    }

private:
    vector<string> generateRandomWords(int n, int maxLength) {
        vector<string> words;
        for (int i = 0; i < n; i++) {
            int len = rnd.nextInt(1, maxLength);
            string word;
            for (int j = 0; j < len; j++) {
                word += char('a' + rnd.nextInt(0, 25));
            }
            words.push_back(word);
        }
        return words;
    }
};
