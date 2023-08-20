interface GoogleSignInParams {
  credential: string;
}

(window as any).onGoogleLogin = (sign_in: GoogleSignInParams) => {
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
