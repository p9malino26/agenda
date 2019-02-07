//some discarded code

    struct LessonDummy
    {
        std::string subject_name;
        
        LessonDummy(){}
        
        LessonDummy(std::string _subject_name)
            :subject_name(_subject_name)
        {}
        
        LessonDummy(const LessonDummy& other)
            :subject_name(other.subject_name)
        {
            std::cout << "Copied!" << std::endl;
        }
    };
    
    template <class KeyType, class ValueType>
    struct MapTree
    {
        //(weeks)
        //       int      weekplan  
        std::map<KeyType, ValueType> m_map;
        
    public:
        ValueType& operator[](KeyType key)
        {
            if(m_map.find(key) == m_map.end())
            {
                m_map.emplace(std::pair( key, ValueType() ) );
            }
            
            return m_map[key];
        }
        
    };
    
    

    
    class DayPlan
    {
    //contains vars like subject name, start time, end time
        friend class Timetable;
        friend class Week;
        std::map<int, Lesson> m_lessons;
        void addSubject(const LessonReference& lessonReference, const Lesson& lesson);
    };

    class Week
    {
        friend class Timetable;
        std::map<Day, DayPlan> m_days;
        void addSubject(const LessonReference& lessonReference, const Lesson& lesson);
    };*/
    
    /*class Day
    {
        std::map<int, std::unique_ptr<LessonDummy>> m_map;
        
        LessonDummy& operator[](int key)
        {
            
        }
    };*/
    
        /*void Timetable::addSubject(const LessonReference& lessonReference, const Lesson& lesson)
    {
        if(m_weeks.find(lessonReference.week) == m_weeks.end()) // if that week hasn't been found
        {
            m_weeks.emplace(lessonReference.week);
        }
        m_weeks[lessonReference.week].addSubject(lessonReference, lesson);
    }
    
    void Week::addSubject(const LessonReference& lessonReference, const Lesson& lesson)
    {
        if(m_days.find(lessonReference.day) == m_days.end()) // if that week hasn't been found
        {
            m_days.emplace(lessonReference.week);
        }
        m_days[lessonReference.day].addSubject(lessonReference, lesson);
    }*/



}

//trash code:

/*
 *      if(m_weeks.find(lessonReference.week) == m_weeks.end()) // if that week hasn't been found
        {
            m_weeks.emplace(lessonReference.week);
        }
        m_weeks[lessonReference.week].addSubject(lessonReference, lesson);
        
        #define ADD_ROOT(ROOT_LIST, LESSON_REFERENCE_ELEMENT) if(ROOT_LIST.find(lessonReference.LESSON_REFERENCE_ELEMENT) == ROOT_LIST.end())\ // if that week hasn't been found
    ROOT_LIST.emplace(lessonReference.LESSON_REFERENCE_ELEMENT);\        
ROOT_LIST[lessonReference.LESSON_REFERENCE_ELEMENT].addSubject(lessonReference, lesson);\
        
 */

//task stuff

        //constructors

        /*Task();
        //Event(string data);
        Task(const Date& date, const std::__cxx11::string& _subject, const std::__cxx11::string& _information);
        Task(const Date& date, const char* _subject, const char* _information);

        string getInfo() const;
        void printInfo() const;*/
