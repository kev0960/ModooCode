window.onGoogleLogin = function (sign_in) {
    fetch("/auth/goog", {
        method: "post",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
        },
        body: JSON.stringify({
            token: sign_in.credential,
        }),
    }).then(function (response) {
        console.log(response);
        location.reload();
    });
};
//# sourceMappingURL=login.js.map