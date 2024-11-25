#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int maxWidth;
    vector<string> words;
    vector<string> result;

    void InputFormat() {
        LINE(words); // Removed SIZE from LINE as it's not valid for LINE.
        LINE(maxWidth);
    }

    void OutputFormat() {
        LINES(result); // LINES automatically handles multiple lines of output.
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(1 <= words.size() && words.size() <= 300);
        CONS(allWordsValid(words));
        CONS(1 <= maxWidth && maxWidth <= 100);
    }

private:
    bool allWordsValid(const vector<string>& words) {
        for (const string& word : words) {
            if (word.size() < 1 || word.size() > 20) {
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
            R"(["This", "is", "an", "example", "of", "text", "justification."])",
            "16"
        });
        Output({
            R"(["This    is    an", "example  of text", "justification.  "])"
        });
    }

    void SampleTestCase2() {
        Input({
            R"(["What", "must", "be", "acknowledgment", "shall", "be"])",
            "16"
        });
        Output({
            R"(["What   must   be", "acknowledgment  ", "shall be        "])"
        });
    }

    void SampleTestCase3() {
        Input({
            R"(["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"])",
            "20"
        });
        Output({
            R"(["Science  is  what we", "understand      well", "enough to explain to", "a  computer.  Art is", "everything  else  we", "do                  "])"
        });
    }

    void BeforeTestCase() {
        words.clear();
        result.clear();
    }

    void TestCases() {
        CASE(words = generateWords(5, 5), maxWidth = 20);
        CASE(words = generateWords(300, 10), maxWidth = 50);
        CASE(words = generateWords(300, 20), maxWidth = 100);
        CASE(words = {"longword1", "longword2", "longword3"}, maxWidth = 30);
        CASE(words = {"singleword"}, maxWidth = 10);
        CASE(words = generateWords(300, 1), maxWidth = 1);
    }

private:
    vector<string> generateWords(int n, int maxLength) {
        vector<string> words;
        for (int i = 0; i < n; i++) {
            int len = rnd.nextInt(1, maxLength);
            string word(len, 'a');
            for (char& c : word) {
                c = 'a' + rnd.nextInt(0, 25);
            }
            words.push_back(word);
        }
        return words;
    }
};
