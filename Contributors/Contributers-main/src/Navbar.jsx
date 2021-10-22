import React from "react";
import { Container, Navbar, Nav } from "react-bootstrap";
export default function mynavbar() {
  return (
    <Navbar bg="warning" variant="dark">
      <Container>
        <Navbar.Brand href="#home">Contributers</Navbar.Brand>
        <Nav className="me">
          <Nav.Link href="#ADD">+Whatsapp Chat</Nav.Link>
        </Nav>
      </Container>
    </Navbar>
  );
}
