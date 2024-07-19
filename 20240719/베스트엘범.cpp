#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> genrePlayCntMap; // 장르별 총재생 횟수
vector<pair<string, int>> genrePlayCntVector; // 정렬을 위해 map을 변환할 vector
map<string, vector<pair<int, int>>> genrePlaylist; // 장르별 각 노래 정보(index, 재생 횟수)
vector<int> answer;

// 장르별 총재생 횟수 기준 정렬에 사용할 비교 함수
bool compPlayCnt(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

// 장르별 각 노래 재생 횟수 기준 정렬에 사용할 비교 함수
bool compPlayList(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    for(int i=0; i<genres.size(); ++i) {
        genrePlayCntMap[genres[i]] += plays[i];
        genrePlaylist[genres[i]].push_back({i, plays[i]});
    }
    
    // 정렬을 위해 map을 vector로 변환
    genrePlayCntVector.assign(genrePlayCntMap.begin(), genrePlayCntMap.end());
    // 장르별 총재생 횟수 기준 정렬
    sort(genrePlayCntVector.begin(), genrePlayCntVector.end(), compPlayCnt);
    
    // 장르별 각 노래 재생 횟수 기준 정렬
    for(auto& it : genrePlaylist) {
        sort(it.second.begin(), it.second.end(), compPlayList);
    }
    
    // 재생 횟수가 높은 장르부터 순회
    for(int i=0; i<genrePlayCntVector.size(); ++i) {
        string genre = genrePlayCntVector[i].first;
        // 각 장르별 재생 횟수가 높은 노래 순으로 앨범에 저장
        for(int j=0; (j<genrePlaylist[genre].size()) && (j<2); ++j) {
            answer.push_back(genrePlaylist[genre][j].first);
        }
    }
    
    return answer;
}

// 참고: https://velog.io/@gntjd135/프로그래머스-베스트앨범-C
// https://resilient-aura-65d.notion.site/53582befe5e74186955b6df993d4567a?pvs=4
