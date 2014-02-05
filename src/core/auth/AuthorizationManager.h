/*
    Copyright (C) 2012  Spatial Transcriptomics AB,
    read LICENSE for licensing terms.
    Contact : Jose Fernandez Navarro <jose.fernandez.navarro@scilifelab.se>

*/

#ifndef AUTHORIZATIONMANAGER_H
#define AUTHORIZATIONMANAGER_H

#include <QObject>
#include <QPointer>
#include <QUuid>

#include "core/auth/TokenStorage.h"
#include "utils/Singleton.h"

class OAuth2;
class QWidget;
class Error;

//  This class implements singleton pattern. It gives an interface for oAuth2 authorization
//  trough the objects OAuth2 and TokenStorage.
//  It emits signals for error, authorized and abortion.
//  It allows for local storage of access token.

class AuthorizationManager : public QObject, public Singleton<AuthorizationManager>
{
    Q_OBJECT

public:

    explicit AuthorizationManager(QObject* parent = 0);
    virtual ~AuthorizationManager();

    void finalize();
    void init();

    //initilize the log in on the QApp (modal)
    void start();

    //clean access token
    void cleanAccesToken();

    inline bool isAuthenticated() const
    {
        return m_tokenStorage->hasAccessToken()
               && !m_tokenStorage->isExpired();
    }

    //force to log out and clean cache
    void forceAuthentication();

    inline bool hasAccessToken() const { return m_tokenStorage->hasAccessToken(); }
    inline QUuid getAccessToken() const { return m_tokenStorage->getAccessToken(); }

signals:

    void signalLoginAborted();
    void signalAuthorize();
    void signalError(Error* error);

private slots:

    void slotLoginDone(const QUuid& accessToken, int expiresIn, const QUuid& refreshToken);

private:

    QScopedPointer<OAuth2> m_oAuth2;
    QScopedPointer<TokenStorage> m_tokenStorage;

};

#endif  /* AUTHORIZATIONMANAGER_H */

