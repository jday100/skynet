class T200DBClient {
    constructor(client) {
        this._client = client;
    }

    connect() {
        return this._client.connect();
    }

    disconnect() {
        return this._client.disconnect();
    }

    query(sql) {
        return this._client.query(sql);
    }

    execute(sql) {
        return this._client.execute(sql);
    }

    begin() {
        return this._client.begin();
    }

    commit() {
        return this._client.commit();
    }

    rollback() {
        return this._client.rollback();
    }
}

module.exports = T200DBClient;