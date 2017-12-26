#pragma once
class TRander
{
public:
        static TRander * GetControl();
        ~TRander();
        static void Clear();
        int GetARandNumber(int low, int high);
        float GetAFBetwen0To1();
protected:
        void Init();
        TRander();
        static TRander * m_control;
};

