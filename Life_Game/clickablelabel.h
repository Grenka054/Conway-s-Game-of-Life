#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    ClickableLabel( const QString & text, QWidget * parent = 0 );
    ~ClickableLabel(){}

signals:
    void clicked();

public slots:
    void slotClicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;

};

#endif // CLICKABLELABEL_H
