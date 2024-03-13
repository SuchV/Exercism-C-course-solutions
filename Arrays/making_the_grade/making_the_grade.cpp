#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded;
    for(auto x : student_scores) rounded.emplace_back(static_cast<int>(x)) ;
    return rounded;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count{0};
    for(auto x : student_scores) {
        if (x < 40) count++;
    }
    return count;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    std::vector<int> filtered;
    for(auto x : student_scores) {
        if(x >= threshold) filtered.emplace_back(x);
    }
    return filtered;
}
// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int step = (highest_score - 40) / 4;
    return std::array<int, 4> {41,41+step,41+(2*step),41+(3*step)};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranked;
    int counter{1};
    for(int score: student_scores){
        ranked.emplace_back(std::to_string(counter) + ". " + student_names.at(counter-1) + ": " +  std::to_string(score));
        counter++;
    }
    return ranked;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    int index{0};
    std::string name{""};
    for(int score: student_scores){
        if (score == 100) return student_names.at(index);
        index++;
    }
    return "";
}
