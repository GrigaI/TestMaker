#ifndef COMMAND_H
#define COMMAND_H

#include <QStringList>

enum TYPES {
    AUTORIZATION,
    SECONDTYPE,
    THIRDTYPE
};


class Command
{
public:
    Command();

    QStringList cmbList();
private:
    QStringList typesList =  {
        "авторизация",
        "второй тип",
        "третий тип"
                        };
};

#endif // COMMAND_H
