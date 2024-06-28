//
//  Timer.hpp
//  PvZ
//
//  Created by lxk on 2024/6/28.
//

#ifndef Timer_hpp
#define Timer_hpp

class Timer {
public:
  Timer (): m_timer(0), m_is_timing(false){}
  Timer (int time): m_timer(time), m_is_timing(false){}
  void StartTimer() {m_is_timing = true;}
  void StopTimer() {m_is_timing = false;}
  void SetTimer(int time) {m_timer = time;}
  bool isTiming() const {return m_is_timing;}
  bool isTimingEnded() const {return m_timer <= 0;}
  void Update() {if(m_is_timing) m_timer--;}
private:
  int m_timer;
  bool m_is_timing;
};

#endif /* Timer_hpp */
