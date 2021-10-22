import React from "react";

export default function Footer() {
  var d = new Date();

  return (
    <footer>
      <p>© {d.getFullYear()} Notes</p>
    </footer>
  );
}
