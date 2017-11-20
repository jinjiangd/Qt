/** 通过qt中的网络请求同步获取时序数据库中数据
 * @brief CInfluxDB::syncHttpRequest
 * @param queryStr sql
 * @return 返回sql结果
 */
QByteArray CInfluxDB::syncHttpRequest(const QString& queryStr)
{
    //QNetworkAccessManager m_pSyncNetworkMgr = new QNetworkAccessManager(this);
    //拼接url地址
    QUrl url = m_hostStr + "query?pretty=true&db=" + m_dbname + "&q=" + queryStr;
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply* reply  = m_pSyncNetworkMgr->get(request);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    return reply->readAll();
}
